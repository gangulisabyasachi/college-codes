----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.03.2025 09:59:48
-- Design Name: 
-- Module Name: NOR_IF_TBW - Behavioral
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

entity NOR_IF_TBW is
--  Port ( );
end NOR_IF_TBW;

architecture Behavioral of NOR_IF_TBW is
component NOR_IF_BH is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : out STD_LOGIC);
end component;
signal A1: STD_LOGIC:='0';
signal B1: STD_LOGIC:='0';
signal C1: STD_LOGIC;
begin
UUT: NOR_IF_BH port map(A=>A1, B=>B1, C=>C1);
Stim_proc:process
begin
wait for 100ns;
A1<='0';
B1<='1';
wait for 100ns;
A1<='1';
B1<='0';
wait for 100ns;
A1<='1';
B1<='1';
wait;
end process;
end Behavioral;

