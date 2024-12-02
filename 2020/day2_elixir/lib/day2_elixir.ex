defmodule Day2Elixir do
  @test_filename "test_input.txt"
  @input_filename "day2_input.txt"

  def convert_line_lst(lst) do
    e0 = Enum.at(lst, 0)
    [e0, e1] = String.split(e0, "-")
    e0 = String.to_integer(e0)
    e1 = String.to_integer(e1)

    {{e0, e1}, Enum.at(lst, 1), String.graphemes(Enum.at(lst, 2))}
  end

  def parse_data_file(filename) do
    {:ok, contents} = File.read(filename)

    String.split(contents, "\n", trim: true)
    |> Enum.map(fn x ->
      String.replace(x, ":", "")
      |> String.split(" ")
    end)
    |> Enum.map(&convert_line_lst/1)
  end

  def password_line_valid_day1(row) do
    {{e0, e1}, ltr, lst} = row

    cnt = Enum.count(lst, fn x -> x == ltr end)

    if cnt >= e0 && cnt <= e1 do
      true
    else
      false
    end
  end

  def password_line_valid_day2(row) do
    {{e0, e1}, ltr, lst} = row

    t1 = Enum.at(lst, e0 - 1) == ltr
    t2 = Enum.at(lst, e1 - 1) == ltr

    IO.inspect(row)

    cond do
      t1 == true && t2 == true -> false
      t1 == false && t2 == false -> false
      t1 == true && t2 == false -> true
      t1 == false && t2 == true -> true
      true -> "huh"
    end
  end

  def run do
    work_data =
      parse_data_file(@input_filename)

    Enum.map(work_data, &password_line_valid_day2/1)
    |> IO.inspect()
    |> Enum.count(fn x -> x == true end)
    |> IO.inspect()
  end

  def part1 do
    work_data =
      parse_data_file(@input_filename)

    Enum.map(work_data, &password_line_valid_day1/1)
    |> Enum.count(fn x -> x == true end)
    |> IO.inspect()
  end
end
