----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 11:02:59
-- Design Name: 
-- Module Name: DECODER_BDF - Behavioral
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

entity DECODER_BDF is
    Port ( ip : in STD_LOGIC_VECTOR (2 downto 0);
           op : out STD_LOGIC_VECTOR (7 downto 0));
end DECODER_BDF;
architecture Behavioral of DECODER_BDF is
begin
process(ip)
begin
op<="00000000";
case ip is
when "000" =>op(0)<='1';
when "001" =>op(1)<='1';
when "010" =>op(2)<='1';
when "011" =>op(3)<='1';
when "100" =>op(4)<='1';
when "101" =>op(5)<='1';
when "110" =>op(6)<='1';
when "111" =>op(7)<='1';
when others=>NULL;
end case;
end process;
end Behavioral;
