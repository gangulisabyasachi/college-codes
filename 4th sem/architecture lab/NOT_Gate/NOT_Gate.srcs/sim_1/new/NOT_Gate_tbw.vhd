----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 07.03.2025 09:56:12
-- Design Name: 
-- Module Name: NOT_Gate_tbw - Dataflow
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

entity NOT_Gate_tbw is
--  Port ( );
end NOT_Gate_tbw;

architecture Dataflow of NOT_Gate_tbw is

component NOT_Gate_df is
    Port ( a : in STD_LOGIC;
           b : out STD_LOGIC);
end component;
signal a1: STD_LOGIC:='0';
signal b1: STD_LOGIC;

begin
UUT: NOT_Gate_df port map(a=>a1, b=>b1);
Stim_proc:process

begin
wait for 100ns;
a1<='0';

wait for 100ns;
a1<='1';

wait;
end process;




end Dataflow;
