require "rubygems"
require "mqtt"

IAM = ARGV.shift
TO = ARGV.shift

MQTT::Client.connect("server.flashinglightprize.nathan.uk0.bigv.io") do |c|
  c.get("ring/#{IAM}") do |topic, message|
    if message == IAM then
      sleep 0.1
      c.publish("ring/#{TO}", TO)
    end
  end
end
