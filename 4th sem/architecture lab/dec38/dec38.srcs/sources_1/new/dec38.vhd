----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 10:53:20
-- Design Name: 
-- Module Name: dec38 - Dataflow
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

entity dec38 is
    Port ( IP : in STD_LOGIC_VECTOR (2 downto 0);
           OP : out STD_LOGIC_VECTOR (7 downto 0));
end dec38;

architecture dataflow of dec38 is

begin
OP(0)<='1' when IP= "000" else '0';
OP(1)<='1' when IP ="001" else '0';
OP(2)<='1' when IP ="010" else '0';
OP(3)<='1' when IP ="011" else '0';
OP(4)<='1' when IP ="100" else '0';
OP(5)<='1' when IP ="101" else '0';
OP(6)<='1' when IP ="110" else '0';
OP(7)<='1' when IP ="111" else '0';
end Dataflow;

