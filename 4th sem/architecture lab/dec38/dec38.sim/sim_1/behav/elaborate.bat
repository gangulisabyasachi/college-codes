@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto e6001521d006410cbd76d05ba6c5ec3d -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot dec38_tbw_behav xil_defaultlib.dec38_tbw -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
