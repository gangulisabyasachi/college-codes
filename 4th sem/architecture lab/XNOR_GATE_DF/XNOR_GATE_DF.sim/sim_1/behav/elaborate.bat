@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto 7d9cc5441b774990b9562d209ab1430c -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot XNOR_GATE_TBW_behav xil_defaultlib.XNOR_GATE_TBW -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
