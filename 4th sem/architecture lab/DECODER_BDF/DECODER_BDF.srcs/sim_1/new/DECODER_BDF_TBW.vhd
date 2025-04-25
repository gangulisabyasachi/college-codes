----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 11:04:16
-- Design Name: 
-- Module Name: DECODER_BDF_TBW - Behavioral
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

entity DECODER_BDF_TBW is
--  Port ( );
end DECODER_BDF_TBW;
architecture Behavioral of DECODER_BDF_TBW is
component DECODER_BDF is
    Port ( ip : in STD_LOGIC_VECTOR (2 downto 0);
           op : out STD_LOGIC_VECTOR (7 downto 0));
end component;
signal ip1: STD_LOGIC_VECTOR (2 downto 0) :="000";
signal op1: STD_LOGIC_VECTOR (7 downto 0) :="00000000" ;
begin
uut: DECODER_BDF port map (ip=>ip1,op=>op1);
stim_proc: process
begin
wait for 100ns;
ip1<="000";
wait for 100ns;
ip1<="001";
wait for 100ns;
ip1<="010";
wait for 100ns;
ip1<="011";
wait for 100ns;
ip1<="100";
wait for 100ns;
ip1<="101";
wait for 100ns;
ip1<="110";
wait for 100ns;
ip1<="111";
end process;
end Behavioral;
