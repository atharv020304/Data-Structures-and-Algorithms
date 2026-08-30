class Solution {
public:

    // This function tries to find an augmenting path starting from a boy.
    //
    // If a girl is:
    //   1. Not currently matched -> we can directly match her with this boy.
    //   2. Already matched -> we try to move her current partner to another
    //      girl. If that is possible, we can give this girl to the current boy.
    //
    // visitedGirl prevents us from visiting the same girl multiple times
    // during one DFS search.
    bool findMatch(
        int boy,
        vector<vector<int>>& grid,
        vector<bool>& visitedGirl,
        vector<int>& girlMatch
    ) {
        int numGirls = grid[0].size();

        // Try every girl for this boy.
        for (int girl = 0; girl < numGirls; girl++) {

            // This boy is interested in this girl,
            // and we haven't already tried this girl in the current DFS.
            if (grid[boy][girl] == 1 && !visitedGirl[girl]) {

                // Mark this girl as visited so that we don't
                // process her again in this DFS search.
                visitedGirl[girl] = true;

                // Case 1:
                // The girl is currently free.
                //
                // We can directly assign her to this boy.
                if (girlMatch[girl] == -1) {
                    girlMatch[girl] = boy;
                    return true;
                }

                // Case 2:
                // The girl is already matched with another boy.
                //
                // Try to find another girl for that boy.
                // If successful, we can move the old boy elsewhere
                // and give this girl to the current boy.
                int previousBoy = girlMatch[girl];

                if (findMatch(
                        previousBoy,
                        grid,
                        visitedGirl,
                        girlMatch
                    )) {

                    girlMatch[girl] = boy;
                    return true;
                }
            }
        }

        // We could not find a girl for this boy.
        return false;
    }


    int maximumInvitations(vector<vector<int>>& grid) {

        int numBoys = grid.size();
        int numGirls = grid[0].size();

        /*
            girlMatch[g] tells us which boy is currently matched
            with girl g.

            Example:

                girlMatch[2] = 5

            means girl 2 is currently matched with boy 5.

            -1 means the girl is currently unmatched.
        */
        vector<int> girlMatch(numGirls, -1);

        int maximumMatches = 0;

        /*
            Try to match every boy one by one.

            For every new boy, we perform a DFS to look for an
            augmenting path.

            An augmenting path is basically a way to rearrange
            some existing matches so that this new boy can also
            get a girl without breaking the existing matches.
        */
        for (int boy = 0; boy < numBoys; boy++) {

            /*
                visitedGirl must be reset for every new DFS.

                We only want to remember which girls we have visited
                during THIS particular attempt to match the boy.

                We should not carry this information over from
                previous boys.
            */
            vector<bool> visitedGirl(numGirls, false);

            // If we successfully find a match for this boy,
            // increase the total number of matches.
            if (findMatch(
                    boy,
                    grid,
                    visitedGirl,
                    girlMatch
                )) {

                maximumMatches++;
            }
        }

        return maximumMatches;
    }
};
