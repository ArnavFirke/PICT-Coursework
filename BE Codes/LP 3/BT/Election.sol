// SPDX-License-Identifier: MIT
// save using .sol extension
pragma solidity ^0.8.0;

contract Election {

    struct Candidate {
        uint id;
        string name;
        uint voteCount;
    }

    struct Voter {
        bool authorized;
        bool voted;
        uint vote;
    }

    address public electionOwner;
    string public electionName;

    mapping(address => Voter) public voters;
    mapping(uint => Candidate) public candidates;
    uint public totalCandidates;
    uint public totalVotes;

    // Allowing Owner only to do changes just like authorizing him only
    modifier ownerOnly() {
        require(msg.sender == electionOwner, "Not authorized");
        _ ;
    }

    constructor(string memory _name) {
        electionOwner = msg.sender;
        electionName = _name;
    }

    // Add candidate to the election
    function addCandidate(string memory _name) public ownerOnly {
        totalCandidates++;
        candidates[totalCandidates] = Candidate(totalCandidates, _name, 0);
    }

    // Authorize voter to vote
    function authorize(address _person) public ownerOnly {
        voters[_person].authorized = true;
    }

    // Voter casts vote for candidate
    function vote(uint _candidateId) public {
        require(voters[msg.sender].authorized, "You are not authorized to vote");
        require(!voters[msg.sender].voted, "You have already voted");
        require(_candidateId > 0 && _candidateId <= totalCandidates, "Invalid candidate");

        voters[msg.sender].voted = true;
        voters[msg.sender].vote = _candidateId;

        candidates[_candidateId].voteCount++;
        totalVotes++;
    }

    // Get all candidate details: Returns arrays of IDs and names
    function getAllCandidates() public view returns (uint[] memory, string[] memory) {
        uint[] memory ids = new uint[](totalCandidates);
        string[] memory names = new string[](totalCandidates);

        for (uint i = 1; i <= totalCandidates; i++) {
            ids[i - 1] = candidates[i].id;
            names[i - 1] = candidates[i].name;
        }

        return (ids, names);
    }

    // End the election
    function endElection() public ownerOnly view returns (string memory winnerName, uint winnerVoteCount) {
        uint winningVoteCount = 0;
        uint winningCandidateId = 0;

        for (uint i = 1; i <= totalCandidates; i++) {
            if (candidates[i].voteCount > winningVoteCount) {
                winningVoteCount = candidates[i].voteCount;
                winningCandidateId = i;
            }
        }
        
        winnerName = candidates[winningCandidateId].name;
        winnerVoteCount = candidates[winningCandidateId].voteCount;
    }
}
