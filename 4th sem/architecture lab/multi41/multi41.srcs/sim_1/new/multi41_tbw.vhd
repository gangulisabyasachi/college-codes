----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 10:41:08
-- Design Name: 
-- Module Name: multi41_tbw - Dataflow
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

entity multi41_tbw is
--  Port ( );
end multi41_tbw;

architecture Dataflow of multi41_tbw is
component multi41 is
    Port ( IP : in STD_LOGIC_VECTOR (3 downto 0);
       S : in STD_LOGIC_VECTOR (1 downto 0);
       Y : out STD_LOGIC);
       end component;
       signal IP1:STD_LOGIC_VECTOR(3 downto 0):="1010";
       signal S1:STD_LOGIC_VECTOR(1 downto 0):="00";
       signal Y1:STD_LOGIC;
begin
uut: multi41 port map (IP=>IP1,S=>S1, Y=>Y1);
stim_proc: process
begin
    wait for 100 ns;
    S1<="00";
    wait for 100 ns;
    S1<="01";
    wait for 100 ns;
     S1<="10";
     wait for 100 ns;
     S1<="11";
     wait;
end process;
end Dataflow;
