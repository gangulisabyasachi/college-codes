----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.03.2025 11:25:27
-- Design Name: 
-- Module Name: FULLADD_TBW - Behavioral
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

entity FULLADD_TBW is
--  Port ( );
end FULLADD_TBW;

architecture Behavioral of FULLADD_TBW is
component FULLADD_BH is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           Cin : in STD_LOGIC;
           S : out STD_LOGIC;
           Cout : out STD_LOGIC);
end component;
signal A1: STD_LOGIC:='0';
signal B1: STD_LOGIC:='0';
signal Cin1: STD_LOGIC:='0';
signal S1: STD_LOGIC;
signal Cout1: STD_LOGIC;


begin
UUT: FULLADD_BH port map(A=>A1, B=>B1, Cin=>Cin1, S=>S1, Cout=>Cout1);

Stim_proc:process
begin
wait for 100ns;
A1<='0';
B1<='0';
Cin1<='1';
wait for 100ns;
A1<='0';
B1<='1';
Cin1<='0';
wait for 100ns;
A1<='0';
B1<='1';
Cin1<='1';
wait for 100ns;
A1<='1';
B1<='0';
Cin1<='0';
wait for 100ns;
A1<='1';
B1<='0';
Cin1<='1';
wait for 100ns;
A1<='1';
B1<='1';
Cin1<='0';
wait for 100ns;
A1<='1';
B1<='1';
Cin1<='1';

wait;
end process;
end Behavioral;
