// locator.cpp - 最终自动定位版
#define _CRT_SECURE_NO_WARNINGS 
#define WIN32_LEAN_AND_MEAN
#define UNICODE
#define _UNICODE

#include <windows.h>
#include <objbase.h>
#include <uiautomation.h>
#include <shellapi.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "uiautomationcore.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "gdi32.lib")

template <class T> void SafeRelease(T** ppT) {
    if (*ppT) { (*ppT)->Release(); *ppT = NULL; }
}

int main() {
    SetProcessDPIAware();
    printf("=== Bilibili Auto Follow Locator ===\n");

    CoInitialize(NULL);
    IUIAutomation* pAutomation = NULL;
    CoCreateInstance(CLSID_CUIAutomation, NULL, CLSCTX_INPROC_SERVER, IID_IUIAutomation, (void**)&pAutomation);

    printf("Opening browser in 3 seconds... Please make sure you are LOGGED IN.\n");
    Sleep(3000);
    ShellExecuteW(NULL, L"open", L"https://b23.tv/4ma9t0l", NULL, NULL, SW_SHOWNORMAL);

    printf("Waiting for page to load (12 seconds)...\n");
    Sleep(12000);

    printf("Searching for 'Follow' button...\n");
    IUIAutomationElement* pRoot = NULL;
    pAutomation->GetRootElement(&pRoot);

    VARIANT varName;
    varName.vt = VT_BSTR;
    varName.bstrVal = SysAllocString(L"关注");
    IUIAutomationCondition* pCondition = NULL;
    pAutomation->CreatePropertyCondition(UIA_NamePropertyId, varName, &pCondition);

    IUIAutomationElement* pFound = NULL;
    pRoot->FindFirst(TreeScope_Subtree, pCondition, &pFound);

    SysFreeString(varName.bstrVal);
    SafeRelease(&pCondition);
    SafeRelease(&pRoot);

    if (!pFound) {
        printf("\n[FAILED] Could not find 'Follow' button. Try increasing the sleep time.\n");
        SafeRelease(&pAutomation); CoUninitialize(); system("pause"); return 1;
    }

    RECT rect;
    pFound->get_CurrentBoundingRectangle(&rect);
    int clickX = rect.left + (rect.right - rect.left) / 2;
    int clickY = rect.top + (rect.bottom - rect.top) / 2;

    printf("[OK] Coordinate locked: X=%d, Y=%d\n", clickX, clickY);

    // 写入坐标文件
    FILE* fp = fopen("target_pos.txt", "w");
    if (fp) {
        fprintf(fp, "%d %d", clickX, clickY);
        fclose(fp);
        printf("Coordinate saved to target_pos.txt\n");
    }

    // 画小白点
    SetCursorPos(clickX, clickY);
    Sleep(500);
    HDC hdc = GetDC(NULL);
    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
    HPEN hRedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hWhiteBrush); SelectObject(hdc, hRedPen);
    int radius = 6;
    Ellipse(hdc, clickX - radius, clickY - radius, clickX + radius, clickY + radius);

    printf("\nTarget marked on screen.\n");
    printf("Locator done. Handing over to Clicker...\n");

    // 程序自动退出，不再等待回车
    Sleep(1000);

    DeleteObject(hWhiteBrush); DeleteObject(hRedPen); ReleaseDC(NULL, hdc);
    SafeRelease(&pFound); SafeRelease(&pAutomation); CoUninitialize();
    return 0;
}