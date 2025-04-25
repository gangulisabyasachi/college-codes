----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 11:11:13
-- Design Name: 
-- Module Name: FULL ADDER STRUCTURAL - Structural
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

entity FULL_ADDER_STRUCTURAL is
    Port ( X : in STD_LOGIC;
           Y : in STD_LOGIC;
           Z : in STD_LOGIC;
           Carry : out STD_LOGIC;
           Sum : out STD_LOGIC);
end FULL_ADDER_STRUCTURAL;

architecture Structural of FULL_ADDER_STRUCTURAL is

component HFADD_DF is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           S : out STD_LOGIC;
           C : out STD_LOGIC);
end component;
component OR_Gate_DF is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : out STD_LOGIC);
end component;
signal S1:STD_LOGIC;
signal C1:STD_LOGIC;
signal C2:STD_LOGIC;
begin
L1:HFADD_DF Port Map(X,Y,S1,C1);
L2:HFADD_DF Port Map(S1,Z,SUM,C2);
L3:OR_Gate_DF Port Map(C1,C2,CARRY);

end structural;
