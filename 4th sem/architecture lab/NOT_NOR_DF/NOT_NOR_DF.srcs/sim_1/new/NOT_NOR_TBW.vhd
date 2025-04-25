----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.03.2025 11:25:05
-- Design Name: 
-- Module Name: NOT_NOR_TBW - Dataflow
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

entity NOT_NOR_TBW is
--  Port ( );
end NOT_NOR_TBW;

architecture Dataflow of NOT_NOR_TBW is
component NOT_NOR_DF is
    Port ( A : in STD_LOGIC;
           B : out STD_LOGIC);
end component;
signal A1: STD_LOGIC:='0';
signal B1: STD_LOGIC;


begin
UUT: NOT_NOR_DF port map(A=>A1, B=>B1);
Stim_proc:process
begin


wait for 100ns;
a1<='0';

wait for 100ns;

a1<='1';

wait;
end process;
end dataflow;
