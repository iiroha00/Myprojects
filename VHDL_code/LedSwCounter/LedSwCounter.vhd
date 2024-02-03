library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity LedSwCounter is
    port(
        sw : in std_logic_vector(3 downto 0);
        led1, led2, led3 : out std_logic
    );
end LedSwCounter;

architecture Behavioral of LedSwCounter is
begin
    led1 <= not sw(3) and not sw(2);
    led2 <= (not sw(3) and sw(2)) or (sw(3) and not sw(2) and not sw(1));
    led3 <= (sw(3) and sw(2)) or (sw(3) and sw(1));
end Behavioral;
