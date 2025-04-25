----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.03.2025 10:55:36
-- Design Name: 
-- Module Name: FULLADD_BH - Behavioral
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

entity FULLADD_BH is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           Cin : in STD_LOGIC;
           S : out STD_LOGIC;
           Cout : out STD_LOGIC);
end FULLADD_BH;

architecture Behavioral of FULLADD_BH is
begin
process(A,B,Cin)
begin
if(A='0') then
if(B=Cin) then
S<='0';
else
S<='1';
end if;
else
if(B=Cin) then
S<='1';
else
S<='0';
end if;
end if;

if((A='1' and B='1') or (B='1' and Cin='1') or (Cin='1' and A='1')) then
Cout<='1';
else
Cout<='0';
end if;
end process;
end Behavioral;
