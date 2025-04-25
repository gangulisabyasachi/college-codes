----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.03.2025 09:58:55
-- Design Name: 
-- Module Name: OR_NAND_TBW - Dataflow
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity OR_NAND_TBW is
--  Port ( );
end OR_NAND_TBW;

architecture Dataflow of OR_NAND_TBW is
component OR_NAND_DF is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : out STD_LOGIC);
end component;
signal a1: STD_LOGIC:='0';
signal b1: STD_LOGIC:='0';
signal c1: STD_LOGIC;
begin
UUT: OR_NAND_DF port map(A=>a1, B=>b1, C=>c1);
Stim_proc:process

begin
wait for 100ns;
a1<='0';
b1<='0';
wait for 100ns;
a1<='0';
b1<='1';
wait for 100ns;
a1<='1';
b1<='0';
wait for 100ns;
a1<='1';
b1<='1';
wait;
end process;
end dataflow;
