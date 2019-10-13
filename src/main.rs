extern crate sysinfo;
use sysinfo::{System, SystemExt, ProcessExt};

use std::process;
use std::{thread, time};

extern crate chrono;
use chrono::{Datelike, Timelike, Utc};

use std::fs::File;
use std::io::Read;

fn main() {


    let mut sys = System::new();

    let pid = process::id() as i32;
    let mut count = 0;
    let mut config_data = String::new();

    loop {

        count += 1;
        if count % 5 == 0 {
            let mut config_file = File::open("src/data.txt").unwrap();
            let mut new_data = String::new();
            config_file.read_to_string(&mut new_data).unwrap();
            config_data = config_data + &new_data;
        }


        sys.refresh_all();

        let now = Utc::now();

        let (is_pm, hour) = now.hour12();
        let time = format!(
            "{:02}:{:02}:{:02} {}",
            hour,
            now.minute(),
            now.second(),
            if is_pm { "PM" } else { "AM" }
        );

        let pinfo : &sysinfo::Process = sys.get_process(pid).unwrap();
        println!("[{}] {} pid={} | Name={} | CpuUsage={:.5}% | MemUsage={}MB",
            time,
            count,
            pinfo.pid(),
            pinfo.name(),
            pinfo.cpu_usage(),
            pinfo.memory() / 1024);

        // To refresh all system information:
        // sys.refresh_all();
        // sys.reset();

        // thread::sleep(time::Duration::from_millis(5000));
        if count > 31 {
            break;
        }
    }



}
