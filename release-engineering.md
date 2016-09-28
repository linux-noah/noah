# Release Engineering

Run the following command:

    $ util/release-engineering 0.2.3

The command includes the following actions...

- Update version constants in noah.h
- Commit and push the changes
- Add a new tag and push it
- Publish the new version on the homebrew repository

A version name must consists of three natural numbers concatenated with two dots, like `0.2.3` or `1.3.11`.
