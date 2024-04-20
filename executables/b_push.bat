@echo off
setlocal EnableDelayedExpansion


if "%1"=="-h" (
    echo This is custom command used to push 
    echo code through the validation pipeline.
    echo Code is only pushed after the pipeline passes.
    echo Sample Usage	
    echo b_push ^<branch_name^> ^<GIT_username^> ^<PAT_token^>	
    exit /b 1
)

set GIT_USERNAME=%2
set BRANCH_NAME=%1
set PROJECT_NAME=TestDrivenProject
set WORKFLOW_NAME=94615098
set ACCESS_TOKEN=%3


if "%BRANCH_NAME%"=="" (
    echo Branch name is missing.
    exit /b 1
)
if "%GIT_USERNAME%"=="" (
    echo GitHub username is missing.
    exit /b 1
)
if "%ACCESS_TOKEN%"=="" (
    echo Personal access token is missing.
    exit /b 1
)

set INPUT_NAME=branch

set INPUT_VALUE=%1Valid

echo curl -X POST ^
  -H "Authorization: token !ACCESS_TOKEN!" ^
  -H "Accept: application/vnd.github.v3+json" ^
	https://api.github.com/repos/%GIT_USERNAME%/%PROJECT_NAME%/actions/workflows/%WORKFLOW_NAME%/dispatches ^
  -d "{\"ref\":\"main\", \"inputs\": {\"!INPUT_NAME!\": \"!INPUT_VALUE!\"}}"
echo.


curl -X POST ^
  -H "Authorization: token %ACCESS_TOKEN%" ^
  -H "Accept: application/vnd.github.v3+json" ^
  https://api.github.com/repos/%GIT_USERNAME%/%PROJECT_NAME%/actions/workflows/%WORKFLOW_NAME%/dispatches ^
  -d "{\"ref\":\"main\", \"inputs\": {\"!INPUT_NAME!\": \"!INPUT_VALUE!\"}}"


endlocal
