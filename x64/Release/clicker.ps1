# clicker.ps1 - 独立点击器 (修复版)
Add-Type @"
    using System;
    using System.Runtime.InteropServices;
    public class MouseClicker {
        [DllImport("user32.dll")]
        public static extern bool SetCursorPos(int X, int Y);
        [DllImport("user32.dll")]
        public static extern void mouse_event(uint dwFlags, uint dx, uint dy, uint dwData, int dwExtraInfo);
        public static void Click(int x, int y) {
            SetCursorPos(x, y);
            System.Threading.Thread.Sleep(500);
            mouse_event(0x0002, 0, 0, 0, 0); // 左键按下
            System.Threading.Thread.Sleep(100);
            mouse_event(0x0004, 0, 0, 0, 0); // 左键抬起
        }
    }
"@

$posFile = "target_pos.txt"
if (-not (Test-Path $posFile)) {
    Write-Host "错误: 未找到 target_pos.txt，请先运行 locator.exe 获取坐标！" -ForegroundColor Red
    exit
}
$content = Get-Content $posFile -Raw
$coords = $content -split '\s+'
$targetX = [int]$coords[0]
$targetY = [int]$coords[1]
[MouseClicker]::Click($targetX, $targetY)
Write-Host "点击执行完毕！请查看浏览器。" -ForegroundColor Green