defmodule Day4Elixir do
  @test_filename "test_input.txt"
  @input_filename "day1_input.txt"

  def part1(filename) do
    {:ok, fdata} = File.read(filename)

    String.split(fdata, "\n")


  end

  def run do
    part1(@test_filename)
  end
end
