@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 5b43329a36b54425be79e81e512d19fa -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot XOR_IF_TBW_behav xil_defaultlib.XOR_IF_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
