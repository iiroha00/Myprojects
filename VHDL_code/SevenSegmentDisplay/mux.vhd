library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux is
  Port ( 
    sel : in std_logic_vector(3 downto 0);
    data_out : out std_logic_vector(6 downto 0)
  );
end mux;

architecture Behavioral of mux is
begin
    process(sel)
    begin
        case sel is
            when "0000" => data_out <= "1000000"; -- 0
            when "0001" => data_out <= "1111001"; -- 1
            when "0010" => data_out <= "0100100"; -- 2
            when "0011" => data_out <= "0110000"; -- 3
            when "0100" => data_out <= "0011001"; -- 4
            when "0101" => data_out <= "0010010"; -- 5
            when "0110" => data_out <= "0000010"; -- 6
            when "0111" => data_out <= "1111000"; -- 7
            when "1000" => data_out <= "0000000"; -- 8
            when "1001" => data_out <= "0010000"; -- 9
            when others => data_out <= "1111111";
        end case;
    end process;
end Behavioral;
