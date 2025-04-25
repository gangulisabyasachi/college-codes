----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 11:19:10
-- Design Name: 
-- Module Name: FULL_ADDER_STRUCTURAL_TBW - Structural
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

entity FULL_ADDER_STRUCTURAL_TBW is
--  Port ( );
end FULL_ADDER_STRUCTURAL_TBW;

architecture structural of FULL_ADDER_STRUCTURAL_TBW is
component FULL_ADDER_STRUCTURAL is
    Port ( X : in STD_LOGIC;
           Y : in STD_LOGIC;
           Z : in STD_LOGIC;
           Sum : out STD_LOGIC;
           Carry : out STD_LOGIC);
end component;
signal a1: STD_LOGIC :='0';
  signal b1: STD_LOGIC :='0';
  signal e1: STD_LOGIC :='0';
  signal c1: STD_LOGIC ;
  signal d1: STD_LOGIC ;

begin
uut: FULL_ADDER_STRUCTURAL port map (X=>a1, Y=>b1, Z=>e1, Sum=>c1,Carry=>d1);
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


end structural;
