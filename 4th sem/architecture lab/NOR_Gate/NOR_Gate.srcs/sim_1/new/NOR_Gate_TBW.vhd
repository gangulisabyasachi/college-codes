----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 07.03.2025 10:26:51
-- Design Name: 
-- Module Name: NOR_Gate_TBW - Dataflow
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

entity NOR_Gate_TBW is
--  Port ( );
end NOR_Gate_TBW;

architecture Dataflow of NOR_Gate_TBW is
component NOR_Gate_DF is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           c : out STD_LOGIC);
end component;
signal a1: STD_LOGIC:='0';
signal b1: STD_LOGIC:='0';
signal c1: STD_LOGIC;


begin
UUT: NOR_Gate_DF port map(a=>a1, b=>b1,c=>c1);
Stim_proc:process
begin
wait for 100ns;
a1<='0';
b1<='0';
wait for 100ns;
a1<='0';
b1<='1';
wait for 100ns;
a1<='1';
b1<='0';
wait for 100ns;
a1<='1';
b1<='1';
wait;
end process;
end Dataflow;

