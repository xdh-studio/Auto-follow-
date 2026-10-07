::[Bat To Exe Converter]
::
::fBE1pAF6MU+EWH3eyHcjLQlHcByXOGK7CL0d5u/H/OWSsE4YaPA6aIDI5pW7FM81x3n8I8IR5H9WncofCSdbchuoZQom535R5wQ=
::fBE1pAF6MU+EWH3eyHcjLQlHcByXOGK7CL0d5u/H/OWSsE4YaPA6aIDI5pW7FM81x3n8I8IR5H9WncofCSdUcRGqegAm52taswQ=
::YAwzoRdxOk+EWAnk
::fBw5plQjdG8=
::YAwzuBVtJxjWCl3EqQJgSA==
::ZR4luwNxJguZRRnk
::Yhs/ulQjdF+5
::cxAkpRVqdFKZSTk=
::cBs/ulQjdF+5
::ZR41oxFsdFKZSDk=
::eBoioBt6dFKZSDk=
::cRo6pxp7LAbNWATEpSI=
::egkzugNsPRvcWATEpSI=
::dAsiuh18IRvcCxnZtBJQ
::cRYluBh/LU+EWAnk
::YxY4rhs+aU+JeA==
::cxY6rQJ7JhzQF1fEqQJQ
::ZQ05rAF9IBncCkqN+0xwdVs0
::ZQ05rAF9IAHYFVzEqQJQ
::eg0/rx1wNQPfEVWB+kM9LVsJDGQ=
::fBEirQZwNQPfEVWB+kM9LVsJDGQ=
::cRolqwZ3JBvQF1fEqQJQ
::dhA7uBVwLU+EWDk=
::YQ03rBFzNR3SWATElA==
::dhAmsQZ3MwfNWATElA==
::ZQ0/vhVqMQ3MEVWAtB9wSA==
::Zg8zqx1/OA3MEVWAtB9wSA==
::dhA7pRFwIByZRRnk
::Zh4grVQjdCyDJGyX8VAjFANBSA2DMmO7CLIgzO3o5P6IsnGYsTG5q0ddMkUL0QCcNqSqcI4otg==
::YB416Ek+ZG8=
::
::
::978f952a14a936cc963da21a135fa983
@echo off
chcp 65001 >nul
cd /d "%~dp0"
locator.exe
powershell -ExecutionPolicy Bypass -File "clicker.ps1"
del "target_pos.txt"
locator.exe
powershell -ExecutionPolicy Bypass -File "clicker.ps1"
del "target_pos.txt"