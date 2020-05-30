/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016-2020 urShadow
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef PAWNREGEX_NATIVES_H_
#define PAWNREGEX_NATIVES_H_

namespace Natives {
// native Regex:Regex_New(const pattern[], E_REGEX_FLAG:flags = REGEX_DEFAULT,
// E_REGEX_GRAMMAR:grammar = REGEX_ECMASCRIPT);
cell Regex_New(Script *script, std::string pattern, E_REGEX_FLAG flags,
               E_REGEX_GRAMMAR grammar);

// native Regex_Delete(&Regex:r);
cell Regex_Delete(Script *script, cell *regex);

// native Regex_Check(const str[], Regex:r, E_MATCH_FLAG:flags = MATCH_DEFAULT);
cell Regex_Check(Script *script, std::string str, RegexPtr regex,
                 E_MATCH_FLAG flags);

// native Regex_Match(const str[], Regex:r, &RegexMatch:m, E_MATCH_FLAG:flags =
// MATCH_DEFAULT);
cell Regex_Match(Script *script, std::string str, RegexPtr regex,
                 cell *match_results, E_MATCH_FLAG flags);

// native Regex_Search(const str[], Regex:r, &RegexMatch:m, &pos, startpos = 0,
// E_MATCH_FLAG:flags = MATCH_DEFAULT);
cell Regex_Search(Script *script, std::string str, RegexPtr regex,
                  cell *match_results, cell *pos, cell startpos,
                  E_MATCH_FLAG flags);

// native Regex_Replace(const str[], Regex:r, const fmt[], dest[],
// E_MATCH_FLAG:flags = MATCH_DEFAULT, size = sizeof dest);
cell Regex_Replace(Script *script, std::string str, RegexPtr regex,
                   std::string fmt, cell *dest, E_MATCH_FLAG flags, cell size);

// native Match_GetGroup(RegexMatch:m, index, dest[], &length, size = sizeof
// dest);
cell Match_GetGroup(Script *script, MatchResultsPtr match_results, cell index,
                    cell *dest, cell *length, cell size);

// native Match_Free(&RegexMatch:m);
cell Match_Free(Script *script, cell *match_results);
}  // namespace Natives
#endif  // PAWNREGEX_NATIVES_H_
