@echo off
setlocal enabledelayedexpansion

set "REPO_DIR=C:\Users\spkumar\Desktop\TestStand"
set "COUNTER_FILE=%REPO_DIR%\commit_counter.txt"

cd /d "%REPO_DIR%"
icacls "%REPO_DIR%" /grant Everyone:F /T

REM Create the counter file starting at 0 if it doesn't exist yet
if not exist "%COUNTER_FILE%" (
    echo 0> "%COUNTER_FILE%"
)

REM Read the current counter value
set /p num=<"%COUNTER_FILE%"

REM Increment it
set /a num=num+1

REM Save the new value back for next run
echo %num%> "%COUNTER_FILE%"

REM Run the git commands
git add .
git commit -m "Commit %num%"
git push -u origin master

echo.
echo Done. Pushed as "Commit %num%".
pause
