@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.1\\bin
call %xv_path%/xelab  -wto eeec3f56f46e40778b6aca73ac04014c -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot and_df_tbw_behav xil_defaultlib.and_df_tbw -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
