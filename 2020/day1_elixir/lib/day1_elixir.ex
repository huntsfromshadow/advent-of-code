defmodule Day1Elixir do
  @moduledoc """
  Documentation for `Day1Elixir`.
  """

  @test_filename "test_input.txt"
  @input_filename "day1_input.txt"

  def break_data_to_int_list(filename) do
    {:ok, contents} = File.read(filename)

    contents
    |> String.split("\n", trim: true)
    |> Enum.map(&String.to_integer/1)
  end

  def day1_p1 do
    dat =
      break_data_to_int_list(@input_filename)
      |> Enum.with_index()

    Enum.each(dat, fn x ->
      {val, idx} = x

      Enum.each(dat, fn y ->
        {val2, idx2} = y
        # Break out only if idxs aren't equal
        if idx2 != idx && val + val2 == 2020 do
          IO.puts("Found it: #{val}, #{val2} -> #{val * val2} ")
        end
      end)
    end)
  end

  @spec cross(any(), any(), any()) :: list()
  def cross(l1, l2, l3) do
    for x <- l1, y <- l2, z <- l3, do: {x,y,z}
  end



  def day1_p2 do
    dat = break_data_to_int_list(@input_filename)

    cross(dat, dat, dat)
    |> Enum.filter( fn ar ->
        #IO.inspect(ar)
        {x,y,z} = ar
        x + y + z == 2020
    end)
    |> Enum.each(fn tu ->
        {x, y, z} = tu
        IO.puts("#{x * y * z}")
    end)
  end

  @spec run() :: {:error, atom()} | {:ok, binary()}
  def run do
    IO.puts("Running P1")
    day1_p1()

    IO.puts("\n\n")

    IO.puts("Running P2")
    day1_p2()
  end
end
