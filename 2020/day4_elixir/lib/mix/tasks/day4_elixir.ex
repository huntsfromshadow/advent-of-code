defmodule Mix.Tasks.Day4Elixir do
  @moduledoc "The hello mix task: `mix help hello`"
  use Mix.Task

  @shortdoc "Simply calls the Hello.say/0 function."
  def run(_) do
    Day4Elixir.run()
  end
end