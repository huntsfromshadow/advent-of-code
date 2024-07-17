use clap::{Args, Parser, Subcommand};

#[derive(Debug, Parser)] // requires `derive` feature
#[command(name = "git")]
#[command(about = "A fictional versioning CLI", long_about = None)]
struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Debug, Subcommand)]
enum Commands {
    Setup(SetupArgs)
}

#[derive(Args, Debug)]
struct SetupArgs {
    day: i32,
    #[arg(short, long)]
    year: Option<i32>,
    #[arg(short, long)]
    language: Option<String>
}

fn main() {
    let args = Cli::parse();

    match args.command {
        Commands::Setup(sargs) => {
            println!("{:?} {:?} {:?}", sargs.day, sargs.year, sargs.language )    
        }
    }
}
