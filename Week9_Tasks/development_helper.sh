#!/bin/bash

# Function to create the development wiki
create_development_wiki() {
    cat > Development_Assistant.md <<EOL
# Development Assistant Wiki

## C++ Hello World

\`\`\`cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
\`\`\`

## Python Hello World

\`\`\`python
print("Hello, World!")
\`\`\`

## Linux Commands

- List files in the current directory:
  \`\`\`bash
  ls
  \`\`\`

- Print the current working directory:
  \`\`\`bash
  pwd
  \`\`\`

- Copy a file:
  \`\`\`bash
  cp source-file destination-directory
  \`\`\`

## Bash Hello World

\`\`\`bash
#!/bin/bash

echo "Hello, World!"
\`\`\`

EOL
}

# Create the development wiki
create_development_wiki

echo "Development Assistant Wiki has been created as 'Development_Assistant.md'."
