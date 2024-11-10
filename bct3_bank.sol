pragma solidity ^0.8.0;

contract BankAccount {
    // Mapping of customer addresses to balances
    mapping(address => uint256) public balances;

    // Function to create a new bank account for the user
    function deposit(uint256 _amount) public payable {
        // Update balance with deposited amount
        balances[msg.sender] +=_amount;
    }

    // Function to withdraw funds from the account
    function withdraw(uint256 _amount) public {
        require(balances[msg.sender] >= _amount, "Insufficient Balance");
        
        // Check if withdrawal is valid and update balance accordingly
        balances[msg.sender] -= _amount;

        // Send withdrawn amount back to user's wallet (this will be handled by the Remix IDE)
    }

    // Function to view current account balance
    function showBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}