@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 617312d88702457794707e3f0c2771a1 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot MULTI41_BF_TBW_behav xil_defaultlib.MULTI41_BF_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
