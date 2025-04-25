@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto a9db7a31f3de482cbe1fda61950b9004 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot NOT_NAND_TBW_behav xil_defaultlib.NOT_NAND_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
