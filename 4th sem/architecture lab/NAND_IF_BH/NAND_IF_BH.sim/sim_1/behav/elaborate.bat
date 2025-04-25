@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto b5fb7317758a4347869b8e5f00f181e7 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot NAND_IF_TBW_behav xil_defaultlib.NAND_IF_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
