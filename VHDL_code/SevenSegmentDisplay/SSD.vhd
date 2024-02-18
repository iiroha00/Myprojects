library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity SSD is
  Port (
    sw : in std_logic_vector(4 downto 0);
    an : out std_logic_vector(3 downto 0);
    seg : out std_logic_vector(6 downto 0)
   );
end SSD;

architecture Behavioral of SSD is
    component mux
        Port ( sel : in std_logic_vector(3 downto 0);
               data_out : out std_logic_vector(6 downto 0)
             );
    end component;

begin
    an(0) <= not sw(4);
    an(1) <= '1';
    an(2) <= '1';
    an(3) <= '1';

    mux_inst : mux
        port map (sel => sw(3 downto 0), data_out => seg);
        
end Behavioral;
