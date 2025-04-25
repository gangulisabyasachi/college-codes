----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 10:31:54
-- Design Name: 
-- Module Name: MUX_2X1_BH_TBW - Behavioral
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

entity MUX_2X1_BH_TBW is
--  Port ( );
end MUX_2X1_BH_TBW;

architecture Behavioral of MUX_2X1_BH_TBW is
component MUX_2X1_BH is
    Port ( A : in STD_LOGIC;
       B : in STD_LOGIC;
       S : in STD_LOGIC;
       Y : out STD_LOGIC);
end component;
signal a1: STD_LOGIC :='0';
  signal b1: STD_LOGIC :='0';
  signal e1: STD_LOGIC :='0';
  signal y1: STD_LOGIC ;

begin
uut: MUX_2X1_BH port map (A=>a1, B=>b1, S=>e1, Y=>y1);
stim_proc: process
begin
wait for 100 ns;
a1<='0';
b1<='0';
e1<='0';
wait for 100 ns;
a1<='0';
b1<='0';
e1<='1';
wait for 100 ns;
a1<='0';
b1<='1';
e1<='0';
wait for 100 ns;
a1<='0';
b1<='1';
e1<='1';
wait for 100 ns;
a1<='1';
b1<='0';
e1<='0';
wait for 100 ns;
a1<='1';
b1<='0';
e1<='1';
wait for 100 ns;
a1<='1';
b1<='1';
e1<='0';
wait for 100 ns;
a1<='1';
b1<='1';
e1<='1';
wait;

end process;
end Behavioral;

