generate:
	g++ ./src/server/server.cpp -o ./bin/server;
	g++ ./src/client/client.cpp -o ./bin/client;
server:
	./bin/server
client:
	./bin/client