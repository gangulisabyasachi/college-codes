----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 10:47:26
-- Design Name: 
-- Module Name: MULTI41_BF - Behavioral
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

entity MULTI41_BF is
    Port ( IP : in STD_LOGIC_VECTOR (3 downto 0);
           S : in STD_LOGIC_VECTOR (1 downto 0);
           Y : out STD_LOGIC);
end MULTI41_BF;

architecture Behavioral of MULTI41_BF is

begin
process(IP,S)
begin
    case S is
    when "00"=>Y<=IP(0);
    when "01"=>Y<=IP(1);
    when "10"=>Y<=IP(2);
    when "11"=>Y<=IP(3);
    when others=>NULL;
    end case;
    end process;

end Behavioral;
