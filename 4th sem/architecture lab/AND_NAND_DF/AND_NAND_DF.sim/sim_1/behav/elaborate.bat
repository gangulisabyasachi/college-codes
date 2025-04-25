@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 3958ba52d1e4495b809484d5bc5448ae -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot AND_NAND_TBW_behav xil_defaultlib.AND_NAND_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
