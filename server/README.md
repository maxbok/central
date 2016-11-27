## Daemon with i/o commands

### On modules

- actions
- retrieve info

## Sinatra app (or maybe WebSocket server)
	
Talks to the daemon

### Api

- index: list all status
- show: show status of a specific module
- post: update module value

## Avahi (Bonjour)

Launch daemon if not yet up
Add service to discover the WebService (sinatra app)
