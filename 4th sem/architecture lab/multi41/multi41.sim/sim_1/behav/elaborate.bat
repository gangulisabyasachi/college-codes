@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 5834597ebe314706a019ddd62bc79a88 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot multi41_tbw_behav xil_defaultlib.multi41_tbw -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
