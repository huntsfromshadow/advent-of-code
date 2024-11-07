defmodule Day4Elixir do
  @test_filename "test_input.txt"
  #@input_filename "day1_input.txt"

  def break_chunk_line(dat) do
    Enum.join(dat, " ")
    |> convert_to_map()

  end

  def parse_file_list(dat) do
    Enum.chunk_by(dat, fn x -> x != "" end)
    |> Enum.filter(fn x -> x != [""] end)
    |> Enum.each(&break_chunk_line/1)
  end

  def part1(filename) do
    {:ok, fdata} = File.read(filename)

    String.split(fdata, "\n")
    |> parse_file_list()
    |> IO.inspect()

  end

  def run do
    part1(@test_filename)
  end
end
