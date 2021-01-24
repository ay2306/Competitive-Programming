# Editorial
1. Maintain a variable `cnt` denoting the current count of continuous stream,
2. Increase `cnt` if current character matches previous one
3. If doesn't match then set `cnt` to 1
4. Update `cnt` and `ans` at the end of loop cycle.