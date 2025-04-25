@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 89dad1a2fea046d7afe80ed19bb18e62 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot AND_IF_TBW_behav xil_defaultlib.AND_IF_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
