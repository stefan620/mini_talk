# Mini Talk - 42 Project

`Mini Talk` is a project that introduces inter-process communication (IPC) using signals. The objective is to create a program that allows communication between two processes: a **server** and a **client**.

---

## Table of Contents

- [About the Project](#about-the-project)
- [Program Requirements](#program-requirements)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Communication Details](#communication-details)
- [Project Highlights](#project-highlights)
- [Bonus](#bonus)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

---

## About the Project

The **Mini Talk** project uses Unix signals (`SIGUSR1` and `SIGUSR2`) to implement a simple messaging system. A **server** process waits for messages from a **client**, which sends a string of characters encoded using signals. The project introduces low-level concepts like signal handling, bit manipulation, and process IDs.

---

## Program Requirements

1. **Server**:
   - Starts and displays its process ID (PID).
   - Receives messages from the client.
   - Outputs the received message to the standard output.

2. **Client**:
   - Sends a string as a message to the server using its PID.
   - Encodes the string into a series of signals (`SIGUSR1` and `SIGUSR2`).

3. **Error Handling**:
   - Ensure that the server PID is valid.
   - Handle edge cases (e.g., empty messages).

---

### Prerequisites

- A GCC-compatible C compiler.
- `make` utility.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/stefan620/mini_talk.git
   cd mini_talk
2. Compile the project:
    ```bash
    make

---

## Usage

1. Start the Server:
  ```bash
./server
```

2. Send a Message from Client:
 ```bash
./client <server_pid> "Your message here"
```
- Replace <server_pid> with the PID displayed by the server.
- Example:
```bash
./client 12345 "Hello, Mini Talk!"
```

3. The server will receive and display the message:
```bash
Received message: Hello, Mini Talk!
```

## Communication Details

### Signal Encoding

- Each character is sent bit by bit using signals:
  - SIGUSR1 represents a binary 0.
  - SIGUSR2 represents a binary 1.
-The client sends each character as an 8-bit binary sequence.
-The server reconstructs the message by handling the signals in the correct order.

### Key Concepts

 - Process IDs (PIDs):
  - The server uses its PID to identify itself to clients.
  - The client sends signals to the server using its PID.

### Signal Handlers:

 - The server sets up handlers to respond to SIGUSR1 and SIGUSR2.

### Synchronization:

- The client and server ensure that signals are sent and processed without loss.

---

### Project Highlights

- Low-Level Programming:
  - Learn how to handle Unix signals and process management.

- Bitwise Operations:
-Encoding and decoding characters using binary representation.

- Error Handling:
  - Handle invalid PIDs, incomplete signals, and unexpected behavior.
 
 ---
 
## Bonus

The bonus part of Mini Talk includes:
  - Unicode Support:
    - Extend the program to support wide characters or multibyte characters.
  - Acknowledgment Mechanism:
    - Implement acknowledgment signals from the server to the client for reliable communication.

---
## Testing

1. Test the program by sending different types of messages:

```bash
./server
./client <server_pid> "42 Network Signals"
```
2. Test edge cases:

  - Empty messages.
  - Long strings.
  - Invalid PIDs.
  - Simultaneous clients.

3. Use tools like htop or ps to monitor processes during testing.

