library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Testbench_LedSwCounter is
end Testbench_LedSwCounter;

architecture Behavioral of Testbench_LedSwCounter is
    signal sw : std_logic_vector(3 downto 0);
    signal led1, led2, led3: std_logic;
begin
    uut: entity work.LedSwCounter
        port map(sw, led1, led2, led3);

    stimulus_process: process
    begin
        -- Test case 1
        sw <= "0000";
        wait for 10 ns;

        -- Test case 2
        sw <= "0001";
        wait for 10 ns;

        -- Test case 3
        sw <= "0010";
        wait for 10 ns;

        -- Test case 4
        sw <= "0011";
        wait for 10 ns;

        -- Test case 5
        sw <= "0100";
        wait for 10 ns;

        -- Test case 6
        sw <= "0101";
        wait for 10 ns;

        -- Test case 7
        sw <= "0110";
        wait for 10 ns;

        -- Test case 8
        sw <= "0111";
        wait for 10 ns;

        -- Test case 9
        sw <= "1000";
        wait for 10 ns;

        -- Test case 10
        sw <= "1001";
        wait for 10 ns;

        -- Test case 11
        sw <= "1010";
        wait for 10 ns;

        -- Test case 12
        sw <= "1011";
        wait for 10 ns;

        -- Test case 13
        sw <= "1100";
        wait for 10 ns;

        -- Test case 14
        sw <= "1101";
        wait for 10 ns;

        -- Test case 15
        sw <= "1110";
        wait for 10 ns;

        -- Test case 16
        sw <= "1111";
        wait for 10 ns;

        wait;  -- Wait indefinitely
    end process stimulus_process;
    
end Behavioral;
