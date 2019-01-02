# AOS-Quiz Application
Quiz Application built using RPC supporting multiple clients and failure recovery.

The server has a list of 50 random questions. A client probes the server and server replies with a random question. On correct answer, the client is awarded one point and zero on wrong reply. A client can ask for server as many times as he wants and server replies with one question each time. There are other clients also requesting the server and are handled in same manner. A client can ask its score and its relative position amongst other clients. A client can go down and can recover. After recovery, it starts with the score it has gained before fault. Once the client wants to finish, it is allowed to exit at any stage. 

Steps to Execute:

1. Run the server using ./assign_server 
 
2. Run one or more clients using ./assign_client <Server IP>

3. On running the client
	
	i)If client machine didn't crash before, then enter client's name.
	
	ii)Client Id will be automatically assigned to the client machine.

	iii)Client can now participate in the quiz.

	Note: Different clients can be simulated by running ./assign_client from different directories.

4. Quiz Menu
	
	i)Get Question - To fetch the question from the server.

	ii)Ask Score - To check the score of the participant.

	iii)Ask Rank - To get the relative position in the leaderboard.

	iv)Get Leaderboard - To get top 10 participants information from the leaderboard.If participants are less than 10
			     everyone's information will be displayed.

	v)Exit - To leave the quiz and remove the participant from the leaderboard.

5. Get Question - If option (i) is selected participant will be shown the question he has to answer. If he answers correctly
		  +1 point is awarded to the participant and 0 on wrong answer,thus affecting his score.

	Note: If the client machine crashes before participant answers the question, next time when he reconnects to the server,
	      quiz will start from the question participant was attempting.

6. For All other options, the client will be acknowledged about the crash but will be given the option to choose from the quiz menu.
