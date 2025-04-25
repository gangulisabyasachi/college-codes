@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto b8e342c5d1914ed185374ef374416bc0 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot OR_NAND_TBW_behav xil_defaultlib.OR_NAND_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
