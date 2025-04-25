----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.04.2025 10:55:05
-- Design Name: 
-- Module Name: dec38_tbw - Dataflow
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

entity dec38_tbw is
--  Port ( );
end dec38_tbw;

architecture dataflow of dec38_tbw is
component dec38 is
       Port ( IP : in STD_LOGIC_VECTOR (2 downto 0);
       OP : out STD_LOGIC_VECTOR (7 downto 0));
       end component;
       signal IP1:STD_LOGIC_VECTOR(2 downto 0):="000";
       signal OP1:STD_LOGIC_VECTOR(7 downto 0);
       
begin
uut: dec38 port map (IP=>IP1,OP=>OP1);
stim_proc: process
begin
    wait for 100 ns;
    IP1<="000";
    wait for 100 ns;
    IP1<="001";   
    wait for 100 ns;
    IP1<="010";
    wait for 100 ns;
    IP1<="011";
    wait for 100 ns;
    IP1<="100";   
    wait for 100 ns;
    IP1<="101";    
    wait for 100 ns;
    IP1<="110";   
    wait for 100 ns;
    IP1<="111"; 
end process;
end dataflow;
