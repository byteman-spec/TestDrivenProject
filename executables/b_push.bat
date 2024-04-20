@echo off

REM Set your repository owner, repository name, workflow name, and access token
set GIT_USERNAME=%2
set BRANCH_NAME=%1
set WORKFLOW_NAME=build_pipeline
set ACCESS_TOKEN=%3

REM Check if the first parameter is -h
if "%1"=="-h" (
    echo This is custom command used to push 
    echo code through the validation pipeline.
    echo Code is only pushed after the pipeline passes.
    echo Sample Usage	
    echo b_push <branch_name> <GIT username> <PAT_token>	
    exit /b 1
)

REM Set your input parameter name
set INPUT_NAME=branch

REM Accept input value as a parameter
set INPUT_VALUE=%1Valid

REM Trigger the workflow using cURL
curl -X POST ^
  -H "Authorization: token %ACCESS_TOKEN%" ^
  -H "Accept: application/vnd.github.v3+json" ^
  https://api.github.com/repos/%GIT_USERNAME%/%BRANCH_NAME%/actions/workflows/%WORKFLOW_NAME%/dispatches ^
  -d "{\"ref\":\"main\", \"inputs\": {\"%INPUT_NAME%\": \"%INPUT_VALUE%\"}}"
